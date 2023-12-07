import express from "express";
import multer from "multer";
import * as personsController from "../controllers/persons.js";

const router = express.Router();
const upload = multer();

router.get("/", personsController.getPersons); // GET
router.get("/:id", personsController.getPerson); // GET
router.post("/", upload.array(), personsController.createPerson); // POST
router.put('/:id', personsController.updatePerson); // UPDATE
router.delete('/:id', personsController.deletePerson); // DELETE

export default router;
