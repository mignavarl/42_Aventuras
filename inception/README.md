*This project has been created as part of the 42 curriculum by mignavar*

# Inception

## Description

Infrastructure project that deploys a WordPress website using Docker containers. Consists of three services: NGINX (web server with TLS), WordPress (PHP-FPM), and MariaDB (database). Each service runs in its own custom container built from Debian Bullseye, orchestrated with Docker Compose.

## Instructions

### Setup

1. Create `.env` file in `srcs/`:
   ```bash
   DOMAIN_NAME=your-domain.42.fr
   MYSQL_DATABASE=wordpress
   MYSQL_USER=wpuser
   WP_ADMIN_USER=admin
   WP_ADMIN_PASSWORD=secure_pass
   WP_ADMIN_EMAIL=admin@example.com
   WP_USER=author
   WP_USER_EMAIL=author@example.com
   WP_USER_PASSWORD=author_pass
   ```

2. Create secrets:
   ```bash
   mkdir -p secrets
   echo "root_password" > secrets/db_root_password.txt
   echo "user_password" > secrets/db_password.txt
   ```

3. Run:
   ```bash
   make        # Build and start
   make down   # Stop
   make fclean # Clean everything
   ```

Access via HTTPS at `https://your-domain.42.fr` (HTTP port 80 returns 405).

## Docker Architecture

**Services**: MariaDB (database), WordPress (PHP-FPM), NGINX (reverse proxy with SSL).

**Network**: Custom bridge network (`inception-network`) for service isolation and discovery.

**Storage**: Bind mounts at `/home/$USER/data/` for persistent data.

**Security**: Docker secrets for credentials, auto-generated SSL certificates.

### Technical Comparisons

**Virtual Machines vs Docker**
- VMs: Full OS with kernel, heavy (GB RAM), slow boot (minutes), hardware isolation
- Docker: Shared kernel, lightweight (MB RAM), fast (seconds), process isolation
- **Choice**: Docker for efficiency and rapid deployment

**Secrets vs Environment Variables**
- Environment: Visible in logs/inspect, simple but insecure
- Secrets: Encrypted, read-only files in `/run/secrets/`, auto-cleanup
- **Choice**: Secrets for database passwords to prevent exposure

**Docker Network vs Host Network**
- Bridge: Isolated namespace, service discovery, port mapping, secure
- Host: Shares host network, no isolation, better performance
- **Choice**: Bridge network for isolation and controlled access

**Docker Volumes vs Bind Mounts**
- Volumes: Docker-managed, portable, better cross-platform
- Bind Mounts: Direct host path mapping, easy host access
- **Choice**: Bind mounts at `/home/$USER/data/` for easy inspection and evaluation requirements

## Resources

**Documentation**: [Docker](https://docs.docker.com/), [Docker Compose](https://docs.docker.com/compose/), [NGINX](https://nginx.org/en/docs/), [MariaDB](https://mariadb.com/kb/), [WordPress](https://developer.wordpress.org/), [Inception Guide](https://dev.to/alejiri/docker-nginx-wordpress-mariadb-tutorial-inception42-1eok/)

**AI Usage**: Documentation writing