import express from "express";
import multer from "multer";
import * as customersController from "../controllers/customers.js";

// We start the router and the multer
const router = express.Router();
const upload = multer();

/**
 * First GET router to get all customers.
 */
router.get("/", customersController.getCustomers);

/**
 * Second GET router to get a customer based on his ID.
 */
router.get("/:id", customersController.getCustomer);

/**
 * POST router to create a new customer.
 */
router.post("/", upload.array(), customersController.createCustomer);

/**
 * UPDATE router to update a customer's information based on his ID.
 */
router.put("/:id", customersController.updateCustomer);

/**
 * DELETE router to delete a customer based on his ID.
 */
router.delete("/:id", customersController.deleteCustomer);

export default router;
