/* istanbul ignore file */
/* tslint:disable */
/* eslint-disable */
import type { MyDto } from '../models/MyDto';

import type { CancelablePromise } from '../core/CancelablePromise';
import { OpenAPI } from '../core/OpenAPI';
import { request as __request } from '../core/request';

export class DemoService {

    /**
     * Retrieve the 'data'
     * @returns MyDto OK
     * @throws ApiError
     */
    public static getData(): CancelablePromise<MyDto> {
        return __request(OpenAPI, {
            method: 'GET',
            url: '/data',
        });
    }

    /**
     * Update the 'data'
     * @param requestBody
     * @returns any OK
     * @throws ApiError
     */
    public static updateData(
        requestBody: MyDto,
    ): CancelablePromise<any> {
        return __request(OpenAPI, {
            method: 'PUT',
            url: '/data',
            body: requestBody,
            mediaType: 'application/json',
        });
    }

}
