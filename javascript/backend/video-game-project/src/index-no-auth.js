import bodyParser from "body-parser";
import cors from "cors";
import express from "express";
import customersRouter from "./routes/customers.js";
import gamesRouter from "./routes/games.js";

/**
 * Setup the apps
 */
const app = express();

/**
 * Setup the bodyParser (URL parser) and the CORS
 */
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use(cors());

/**
 * Setup the Games router.
 */
app.use("/api/games", gamesRouter);

/**
 * Setup the Customers router.
 */
app.use("/api/customers", customersRouter);

/**
 * Launching the API on port 5001.
 */
app.listen(5001, () => {
    console.log("API launched. Port 5001 used. Listening...");
});
