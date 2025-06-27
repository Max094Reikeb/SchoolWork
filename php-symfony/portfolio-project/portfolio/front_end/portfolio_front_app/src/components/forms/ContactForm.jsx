import React, {useState} from "react";

function ContactForm({ onSubmit }) {

    // On initialise les champs 'name', 'email' et 'messages' à vide
    const [formData, setFormData] = useState({name: "", email: "", message: ""});

    const handleChange = (e) => {
        const {name, value} = e.target;
        setFormData((prev) => ({...prev, [name]: value}));
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        onSubmit(formData);

        // On réinitialise ensuite le formulaire en remettant tous les champs à vide après envoi réussi
        setFormData({name: "", email: "", message: ""});
    };

    return (
        <form onSubmit={handleSubmit} style={{maxWidth: '600px'}}>
            <div>
                <label htmlFor="name">Name</label><br/>
                <input id="name" type="text" name="name" value={formData.name} onChange={handleChange} required/>
            </div>
            <div>
                <label htmlFor="email">Email</label><br/>
                <input id="email" type="email" name="email" value={formData.email} onChange={handleChange} required/>
            </div>
            <div>
                <label htmlFor="message">Message</label><br/>
                <textarea id="message" name="message" value={formData.message} onChange={handleChange} required/>
            </div>

            <button type="submit" style={{marginTop: '1rem'}}>Envoyer</button>
        </form>
    );
}

export default ContactForm;