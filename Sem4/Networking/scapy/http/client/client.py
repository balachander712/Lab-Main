import requests
import http.client
import json

conn = http.client.HTTPConnection("localhost", 3000)


def get(file):
    print(file)
    conn.request("GET", '/' + file)
    res = conn.getresponse()
    print(f'Status : {res.status} Reason : {res.reason}')


def post(data, file):
    print(data)
    headers = {'Content-type' : 'application/json'}
    json_data = json.dumps(data)
    conn.request('POST','/' + file, json_data, headers)
    res = conn.getresponse()
    print(res.read())

def put(data, file):
    print(data)
    headers = {'Content-type' : 'application/json'}
    json_data = json.dumps(data)
    conn.request('PUT','/' + file, json_data, headers)
    res = conn.getresponse()
    print(res.read())

def delete(file):
    conn.request('DELETE', '/' + file)
    res = conn.getresponse()
    print(f'Status : {res.status} Reason : {res.reason}')

if __name__ == "__main__":
    REQUEST = input('Enter GET/POST/PUT/DELETE Request ')
    if REQUEST == 'GET':
        file = input('Enter the html file you are looking for : ')
        get(file)
    elif REQUEST == 'POST':
        data = dict()
        file = input('Enter the file name : ')
        foo = input('Enter the data to be posted as a Python dictonary : ')
        data['content'] = foo
        post(data,file)
    elif REQUEST == 'DELETE':
        file = input('Enter the file name : ')
        delete(file)
    elif REQUEST == 'PUT':
        data = dict()
        file = input('Enter the file name : ')
        foo = input('Enter the data to be posted as a Python dictonary : ')
        data['content'] = foo
        put(data,file)
    else:
        print('Enter valid Request...')

    conn.close()