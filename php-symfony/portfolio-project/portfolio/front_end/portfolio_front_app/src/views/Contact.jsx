import React, { useState } from "react";
import axios from 'axios'; // Pour installer 'axios' => 'npm install axios' dans le conteneur react.
import Header from "../components/layouts/Header";
import ContactForm from "../components/forms/ContactForm";

function Contact() {

    const [status, setStatus] = useState(null);
    const handleSubmit = async (formData) => {

        setStatus(null);

        try {
            await axios.post('https://localhost/api/contact', formData);
            setStatus('Message envoyé avec succès.');
        } catch (error) {
            setStatus('Une erreur est survenue. Veuillez essayer de nouveau.');
        }
    };

    return (
        <div style={{ padding: "2rem" }}>
            <Header title="Formulaire de contact" />
            <ContactForm onSubmit={handleSubmit} />
            {status && <p style={{ marginTop: '1rem' }}>{status}</p>}
        </div>
    );
}

export default Contact;