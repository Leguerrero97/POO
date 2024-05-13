from fastapi import FastAPI, HTTPException
from pymongo import MongoClient

app = FastAPI()

# Conexión a la base de datos MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['ejercicio15']
collection = db['Usuario']

# Definir un modelo para la solicitud de autenticación
from pydantic import BaseModel

class UserIn(BaseModel):
    usuario: str
    clave: str

# Definir el endpoint para validar usuarios
@app.post("/validar_usuario/")
async def validar_usuario(user_in: UserIn):
    user_data = collection.find_one({"usuario": user_in.usuario, "clave": user_in.clave})
    if user_data:
        return {"mensaje": "Usuario validado correctamente"}
    else:
        raise HTTPException(status_code=404, detail="Usuario no encontrado o contraseña incorrecta")
