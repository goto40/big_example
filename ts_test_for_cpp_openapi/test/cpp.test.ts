import {DemoApi, MyDto} from "../src/generated-sources/openapi/api"

test("set get test", async () => {
    const app = new DemoApi();

    {
        app.updateData({message: "Tom"});

        const data = (await app.getData()).body;
        expect( data ).toEqual({message: "Tom"});
    }

    {
        app.updateData({message: "Jerry"});

        const data = (await app.getData()).body;
        expect( data ).toEqual({message: "Jerry"});
    }
});