A playground to play with different technologies and libs...

# C++ Web Service implemented with Oat++ 

## cpp_openapi_with_oat: C++ Oat Service

   * src: main code
   * test: unittests
   * oat_test: oat++ unittests
   * `sh build.sh` (then start ./App in build folder)


## api-spec: extracted openapi spec from C++ Oat Service
(manually from running C++ application/swagger UI)

After building the SW, you can run ./App and open http://localhost:8000 
(here you find a link to the spec.):

<img src="doc/swagger.png" width="350" />


## ts_from_cpp_openapi: Typescript test for C++ Oat Service
   * `npm i`
   * `npm test`
   * (to update code if a new api-spec is extracted: `npm run update-lib`)


## py_manual_request for C++ Oat Service 
   * `py.test` (pytest and requests are installed in the docker)


## py_from_cpp_openapi: Python test for C++ Oat Service
   * (to update code from running ./App: `./update-api`)
   * `cd big-example-demo-client`
   * `py.test`


# C++ MQTT Service 

## mosquitto

Links: https://www.arubacloud.com/tutorial/how-to-install-and-secure-mosquitto-on-ubuntu-20-04.aspx

The mosquitto broker (MQTT) is started in decontainer.json automatically.
Try it out:

  * Shell 1: `mosquitto_sub -h localhost -t /demo/data0`
  * Shell 2: `mosquitto_pub -h localhost -t /demo/data0 -m "Hello"`

## TODO: C++ MQTT Service

  * Links: https://github.com/redboltz/mqtt_cpp 