Lanzar el endpoint:uvicorn Connection:app --reload

Metodo para probar la conexion PowerShell:Invoke-RestMethod -Method Post -Uri http://127.0.0.1:8000/validar_usuario/ -Body '{"usuario": "AWALLENSTEIN", "clave": "12345"}' -ContentType "application/json"

