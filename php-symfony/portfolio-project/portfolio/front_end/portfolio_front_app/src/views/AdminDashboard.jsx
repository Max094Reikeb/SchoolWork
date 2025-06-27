import React, {useEffect, useState } from "react";
import axios from 'axios'; // Pour installer 'axios' => 'npm install axios' dans le conteneur react.
import Header from "../components/layouts/Header";
import MessageCard from "../components/messages/MessageCard";

function AdminDashboard() {
    const [messages, setMessages] = useState([]);
    const [error, setError] = useState(null);

    useEffect(() => {
        const fetchMessages = async () => {
            try {
                const response = await axios.get('https://localhost/api/messages');
                setMessages(response.data);
            } catch (error) {
                setError('Erreur : impossible de récupérer les messages.');
            }
        };

        fetchMessages();
    }, []);

    return (
        <div style={{ padding: '2rem' }}>
            <Header title="Liste des messages reçus" />
            {error && <p>{error}</p>}
            <div>
                {messages && messages.length > 0 ? (
                    messages.map((msg) => (
                        <MessageCard key={msg.id} message={msg} />
                    ))
                ) : (
                    <p>Récupération des messages en cours...</p>
                )}
            </div>
        </div>
    );
}

export default AdminDashboard;