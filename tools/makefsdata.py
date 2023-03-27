'''
File: makefsdata.py

Copyright (c) 2020 Diego Asanza <f.asanza@gmail.com>

SPDX-License-Identifier: Apache-2.0
'''

#!/usr/bin/env python3

import os
import sys
import subprocess
import time
import argparse
import pathlib
import mimetypes


def get_relative_path(root, path):
    return path.strip(root)

template = """

/*
 * Copyright (c) 2023 Diego Asanza <f.asanza@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* this file was generated automagically. DO NOT MODIFY */

#include <stdlib.h>
#include <string.h>
#include "makefs.h"
#include <esp_http_server.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

struct hfile {
    const char* data;
    uint32_t len;
};

static esp_err_t file_handler(httpd_req_t *req) {
    struct hfile* f = req->user_ctx;    
    httpd_send(req, f->data, f->len);
    return ESP_OK;
}

"""

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--persistent',
                        action='store_true', help='Set keep-alive header')
    parser.add_argument('folder', help='path with the fs folder')
    parser.add_argument('output', help='output file')

    arg = parser.parse_args()

    with open(arg.output, 'w+') as out:
        out.write(template)
        for root, folders, files in os.walk(arg.folder):
            for file in files:
                header = ''
                if '404' in file:
                    header += 'HTTP/1.1 404 File not found\r\n'
                else:
                    header += 'HTTP/1.1 200 OK\r\n'

                if arg.persistent:
                    header += 'Connection: keep-alive\r\n'
                else:
                    header += 'Connection: close\r\n'

                header += 'Server: LWIP (https://savannah.nongnu.org/projects/lwip/)\r\n'

                # add javascript mimetype bc my windows does not have it
                mimetypes.add_type(('text/javascript'), '.js', strict=True)
                mimetype = mimetypes.guess_type(file)

                header += 'Content-Type: {}\r\n'.format(mimetype[0])
                header += 'Content-Encoding: {}\r\n'.format(mimetype[1])

                path = pathlib.Path(os.path.join(root, file))
                header += 'Content-Length: {}\r\n'.format(
                    os.path.getsize(path))

                header += '\r\n'

                name = str(path.relative_to(arg.folder))

                out.write('static const char http_data_{0:s}[] = {{'.format(
                    name.replace(os.sep, '_').replace('.', '_')))

                out.write(','.join('0x{0:02x}'.format(l)
                                   for l in header.encode('utf-8')))
                out.write(',')

                with open(path, 'rb') as f:
                    out.write(','.join('0x{0:02x}'.format(l)
                                       for l in f.read()))
                out.write('};\r\n')
                out.write('static struct hfile hfile_{} = {{'.format(
                    name.replace(os.sep, '_').replace('.', '_')))
                out.write('.data = http_data_{},'.format(
                    name.replace(os.sep, '_').replace('.', '_')))
                out.write('.len = sizeof(http_data_{}),'.format(
                    name.replace(os.sep, '_').replace('.', '_')))
                out.write('};')

        out.write('static const httpd_uri_t fsdata_root [] = {')
        for root, folders, files in os.walk(arg.folder):
            for file in files:
                path = pathlib.Path(os.path.join(root, file))
                path = str(path.relative_to(arg.folder))
                uri =  (os.sep + path).replace('\\', '/')

                if( uri.lower() == '/index.html'):
                    # index.html is also the default / url
                    out.write('{.uri = "/",')
                    out.write('.method = HTTP_GET,')
                    out.write('.handler = file_handler,')
                    out.write('.user_ctx = &hfile_{},'.format(
                        path.replace(os.sep, '_').replace('.', '_')))
                    out.write('},\r\n')

                out.write('{{.uri = "{}",'.format(uri))
                out.write('.method = HTTP_GET,')
                out.write('.handler = file_handler,')
                out.write('.user_ctx = &hfile_{},'.format(
                    path.replace(os.sep, '_').replace('.', '_')))
                out.write('},\r\n')

        out.write('};\r\n')

        out.write("""const httpd_uri_t* httpd_get_handler_array(int* len) {
                *len = ARRAY_SIZE(fsdata_root);
                return &fsdata_root[0];
            }
            
            const httpd_uri_t* httpd_get_handler(const char* uri) {
                for(int i = 0; i < ARRAY_SIZE(fsdata_root); i++) {
                    if(strcmp(fsdata_root[i].uri, uri) == 0) {
                        return &fsdata_root[i];
                    }
                }
                return NULL;
            }
            
            """)

    lc = ["clang-format", "-i", arg.output]
    retcode = subprocess.call(lc)
    exit(retcode)
