import {DemoApi, MyDto} from "../src/generated-sources/openapi/api"

test("set get test", async () => {
    const app = new DemoApi();
    const data = (await app.getData()).body;
    expect( data ).toEqual({message: "Hello World!"});
});