from fastapi import FastAPI, HTTPException
from pymongo import MongoClient
from pymongo.errors import PyMongoError 
from pydantic import BaseModel

app = FastAPI()

# Conexión a la base de datos MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['ejercicio16cont']
collection = db['usuarios'] 

class UserIn(BaseModel):
    usuario: str
    clave: str

@app.post("/validar_usuario/")
async def validar_usuario(user_in: UserIn):
    try:
        user_data = collection.find_one({"usuario": user_in.usuario, "clave": user_in.clave})

        if user_data:
            nombre = user_data.get("nombre", "")
            apellido = user_data.get("apellido", "")
            return f"{nombre}::{apellido}"
        else:
            raise HTTPException(status_code=401, detail="Credenciales incorrectas")
    except PyMongoError as e:
        raise HTTPException(status_code=500, detail=f"Error de base de datos: {e}")


