from big_example_demo_client import Client
from big_example_demo_client.api.demo import get_data 
from big_example_demo_client.api.demo import update_data 
from big_example_demo_client.models.my_dto import MyDto

def test_cpp():
    client = Client(base_url="http://localhost:8000")

    update_data.sync_detailed(client=client,json_body=MyDto(message='Hubert'))
    data = get_data.sync(client=client)
    assert data.message == 'Hubert'

    update_data.sync_detailed(client=client,json_body=MyDto(message='Staller'))
    data = get_data.sync(client=client)
    assert data.message == 'Staller'
