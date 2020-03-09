const Koa = require('koa');
const { users } = require('./routes/users');
const bodyParser = require('koa-bodyparser');
const mysql = require('mysql2/promise');


const PORT = process.env.PORT || 3000;


async function main() {
    const app = new Koa();

    const authDbConn = await mysql.createConnection({
        host: 'localhost',
        user: 'trinity',
        password: 'trinity',
        database: 'auth'
    });

    app.use(async function(ctx, next) {
        ctx.db = { auth: authDbConn };
        await next();
    });

    app.use(bodyParser());

    app.use(users.routes());

    app.listen(PORT, () => {
        console.log(`Server up and running on port: ${PORT}`)
    });

}

main()
    .catch(ex => {
        console.error('application terminated due to an unexpected exception.');
        console.error(ex);
    })