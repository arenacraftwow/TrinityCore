export interface CreateUserRequest {
    username: string;
    password: string;
    reCaptchaKey: string;
}

export type CreateUserResponse =
    { type: 'Ok' } |
    { type: 'UsernameTaken' } |
    { type: 'InvalidCaptchaCode' } 