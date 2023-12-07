import express from "express";
import bodyParser from "body-parser";
import personsRouter from "./routes/persons.js";

const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.use("/api/persons", personsRouter);

app.listen(5001, () => {
    console.log("On écoute sur le port 5001");
});
