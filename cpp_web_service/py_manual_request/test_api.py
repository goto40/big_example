import requests
import json

def test_api():
    put_data={'message':'Max'}
    headers = {"Content-Type": "application/json"}
    response = requests.put('http://localhost:8000/data', data=json.dumps(put_data), headers=headers)
    assert response.status_code == 200

    response = requests.get('http://localhost:8000/data')
    assert response.status_code == 200
    data = json.loads(response.content)
    assert data["message"] == "Max"

    put_data={'message':'Moriz'}
    headers = {"Content-Type": "application/json"}
    response = requests.put('http://localhost:8000/data', data=json.dumps(put_data), headers=headers)
    assert response.status_code == 200

    response = requests.get('http://localhost:8000/data')
    assert response.status_code == 200
    data = json.loads(response.content)
    assert data["message"] == "Moriz"
