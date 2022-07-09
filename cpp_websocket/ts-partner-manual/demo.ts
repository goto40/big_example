import {WebSocket, MessageEVent} from 'isomorphic-ws'
import { encode, decode } from "@msgpack/msgpack";
import {Buffer} from 'node:buffer'

// npx tsx demo.ts 
console.log("Websocket demo")

const ws = new WebSocket('ws://127.0.0.1:9090/');

ws.onopen = function open() {
  console.log('onopen');
  const data = {
    text: "Request-text",
    values: [512,2,3,4]
  };
  const encoded = encode(data);
  const buffer: Buffer = Buffer.from(encoded.buffer, encoded.byteOffset, encoded.byteLength);
  ws.send(buffer);
};

ws.onclose = function close() {
  console.log('onclose');
};

ws.onmessage = function incoming(event:MessageEVent) {
  console.log("onmessage")
  obj = decode(event.data);
  console.log(obj)
};