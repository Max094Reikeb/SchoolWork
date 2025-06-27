import { BrowserRouter as Router, Routes, Route, Navigate } from 'react-router-dom'; // Pour installer 'react-router-dom' => 'npm install react-router-dom' dans le conteneur react.
import './App.css';
import Home from './views/Home';
import Contact from './views/Contact';
import AdminDashboard from './views/AdminDashboard';

function App() {

  return (
      <Router>
          <Routes>
              <Route path="/" element={<Home />}></Route>
              <Route path="/contact" element={<Contact />}></Route>
              <Route path="/adminDashboard" element={<AdminDashboard />}></Route>
              <Route path="*" element={<Navigate to="/" />}></Route>
          </Routes>
      </Router>
  )
}

export default App
