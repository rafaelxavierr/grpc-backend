# Usa a imagem base do Node.js
FROM node:18-slim

# Define o diretório de trabalho
WORKDIR /app

# Copia os arquivos do projeto para o contêiner
COPY package*.json ./
COPY . .

# Instala as dependências
RUN npm install

# Porta exposta
EXPOSE 8080

# Comando para executar o servidor
CMD ["node", "api_gateway.js"]
