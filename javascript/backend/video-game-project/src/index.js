import bodyParser from "body-parser";
import express from "express";
import OAuth2Server from "oauth2-server";
import {authenticateRequest, oauth} from "./oauth.js";
import customersRouter from "./routes/customers.js";
import gamesRouter from "./routes/games.js";

/**
 * Setup the apps
 */
const app = express();

/**
 * Setup the bodyParser (URL parser)
 */
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

/**
 * POST router to create a new OAuth token
 */
app.post('/oauth/token', (req, res, next) => {
    const request = new OAuth2Server.Request(req);
    const response = new OAuth2Server.Response(res);
    oauth.token(request, response)
        .then((token) => {
            res.json(token);
        }).catch(next);
});

/**
 * Setup the Games router.
 */
app.use("/api/games", authenticateRequest, gamesRouter);

/**
 * Setup the Customers router.
 */
app.use("/api/customers", authenticateRequest, customersRouter);

/**
 * Launching the API on port 5001.
 */
app.listen(5001, () => {
    console.log("API launched. Port 5001 used. Listening...");
});
