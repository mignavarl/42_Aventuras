#!/bin/bash
set -e

mkdir -p /etc/nginx/ssl

: "${DOMAIN_NAME:=localhost}"

if [ ! -f /etc/nginx/ssl/nginx.crt ]; then
    echo "Generando certificado SSL para ${DOMAIN_NAME}..."

    # Generate a self-signed certificate valid for 365 days
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/nginx.key \
        -out /etc/nginx/ssl/nginx.crt \
        -subj "/C=US/ST=State/L=City/O=Organization/CN=${DOMAIN_NAME}"

    chmod 600 /etc/nginx/ssl/nginx.key
    chmod 644 /etc/nginx/ssl/nginx.crt

    echo "Certificado SSL creado en /etc/nginx/ssl/"
else
    echo "El certificado SSL ya existe. Pasando."
fi

# Substitute DOMAIN_NAME in nginx config
echo "Substituting domain name in nginx configuration..."
sed "s/\${DOMAIN_NAME}/$DOMAIN_NAME/g" /etc/nginx/nginx.conf > /tmp/nginx.conf
mv /tmp/nginx.conf /etc/nginx/nginx.conf

echo "Probando configuracion nginx..."
nginx -t #Verify the syntax of Nginx configuration files without restarting the server
echo "Tests nginx correctos"

echo "Iniciando Nginx"
exec nginx -g "daemon off;" # Foreground
