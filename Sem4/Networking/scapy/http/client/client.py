import requests
import http.client
import json

conn = http.client.HTTPConnection("localhost", 3000)


def get(file):
    print(file)
    conn.request("GET", file)
    res = conn.getresponse()
    print(f'Status : {res.status} Reason : {res.reason}')


def post(data):
    headers = {'Content-type' : 'application/json'}
    json_data = json.dumps(data)
    conn.request('POST','/post', json_data, headers)
    res = conn.getresponse()
    print(res.read().decode())


if __name__ == "__main__":
    REQUEST = input('Enter GET/POST/PUT/DELETE Request ')
    if REQUEST == 'GET':
        file = input('Enter the html file you are looking for : ')
        get(file)
    elif REQUEST == 'POST':
        data = dict()
        foo = input('Enter the data to be posted as a Python dictonary')
        data['content'] = foo
    elif REQUEST == 'DELETE':
        pass
    elif REQUEST == 'PUT':
        pass
    else:
        print('Enter valid Request...')