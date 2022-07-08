import {WebSocket} from 'isomorphic-ws'

// npx tsx demo.ts 
console.log("Websocket demo")

const ws = new WebSocket('ws://127.0.0.1:9090/');

ws.onopen = function open() {
  console.log('connected');
  ws.send(Date.now());
};

ws.onclose = function close() {
  console.log('disconnected');
};

ws.onmessage = function incoming(data) {
  console.log(`Roundtrip time: ${Date.now() - data.data} ms`);

  setTimeout(function timeout() {
    ws.send(Date.now());
  }, 500);
};