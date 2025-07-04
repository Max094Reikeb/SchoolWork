import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react-swc'

// https://vite.dev/config/
export default defineConfig({
  plugins: [react()],
  server: {
    host: '0.0.0.0',
    port: 3000,
    strictPort: true,
    hmr: {
      protocol: 'wss', //websockets sécurisés
      host: 'localhost',
      clientPort: 3000
    },
    watch: {
      usePolling: true,
      interval: 100,
    }
  }
})
