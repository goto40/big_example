#!/bin/bash
pip install openapi-python-client
#openapi-python-client generate --url http://localhost:8000/api-docs/oas-3.0.0.json
openapi-python-client update --url http://localhost:8000/api-docs/oas-3.0.0.json
