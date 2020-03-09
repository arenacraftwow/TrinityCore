import { CreateUserRequest, CreateUserResponse } from "./userService";
import { sleepRandom } from "util/sleep";

export const userService = {
    async createUser(req: CreateUserRequest): Promise<CreateUserResponse> {
        await sleepRandom();
        if (Math.random() > 0.5) {
            return { type: 'Ok' }
        } else if (Math.random() > 0.5) {
            return { type: 'UsernameTaken' };
        } else {
            return { type: 'InvalidCaptchaCode' };
        }
    }
}