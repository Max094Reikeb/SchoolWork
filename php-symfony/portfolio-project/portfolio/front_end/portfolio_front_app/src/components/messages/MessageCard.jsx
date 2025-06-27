import React from "react";

function MessageCard({ message }) {
    return (
        <div style={{ border: '1px solid #ccc', padding: '1rem', marginBottom: '1rem' }}>
            <strong>{message.name}</strong> : ({message.email})<br />
            <em>{message.message}</em><br />
            <small>Message reçu le {new Date(message.createdAt).toLocaleString()}</small>
        </div>
    );
}

export default MessageCard;