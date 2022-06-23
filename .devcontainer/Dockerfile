FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-ubuntu-21.04

RUN apt update -y
RUN apt install -y catch

RUN git clone https://github.com/oatpp/oatpp.git
RUN cd oatpp/ && mkdir build && cd build && cmake .. && make install 

RUN git clone https://github.com/oatpp/oatpp-swagger.git
RUN cd oatpp-swagger/ && mkdir build && cd build && cmake .. && make install 

RUN sudo apt install -y nodejs npm
RUN sudo apt install -y openjdk-17-jre