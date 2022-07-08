FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-ubuntu-22.04

RUN apt update -y
RUN apt install -y catch

RUN sudo apt install -y nodejs npm

RUN sudo apt install -y pip
RUN pip install pytest requests

RUN sudo apt update -y && sudo apt install mosquitto mosquitto-clients -y

RUN git clone https://github.com/oatpp/oatpp.git
RUN cd oatpp/ && mkdir build && cd build && cmake .. && make install 

RUN git clone https://github.com/oatpp/oatpp-swagger.git
RUN cd oatpp-swagger/ && mkdir build && cd build && cmake .. && make install 

RUN apt install -y libboost-dev nlohmann-json3-dev
RUN git clone https://github.com/msgpack/msgpack-c.git
RUN cd msgpack-c/ && git checkout cpp_master && mkdir build && cd build && cmake .. && make install

