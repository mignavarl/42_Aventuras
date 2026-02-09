# Developer Documentation - Inception

## Environment Setup from Scratch

**Prerequisites**: Docker, Docker Compose, Make, Linux with sudo

**Setup**:
1. Create `srcs/.env`:
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

3. Update hosts (local dev):
   ```bash
   echo "127.0.0.1 your-domain.42.fr" | sudo tee -a /etc/hosts
   ```

## Building and Launching

**Makefile**:
```bash
make          # Build and start
make build    # Build images only
make up       # Start containers
make down     # Stop containers
make fclean   # Remove everything (including data)
make re       # Rebuild from scratch
```

**Docker Compose**:
```bash
docker compose -f srcs/docker-compose.yml build
docker compose -f srcs/docker-compose.yml up -d
docker compose -f srcs/docker-compose.yml down
docker compose -f srcs/docker-compose.yml logs -f
```

## Container Management

**Basic operations**:
```bash
docker ps                           # List running containers
docker exec -it mariadb bash        # Shell access
docker logs mariadb -f              # View logs
docker restart mariadb              # Restart container
```

**Database access**:
```bash
docker exec -it mariadb mysql -u root -p
docker exec mariadb mysqldump -u root -p'pass' wordpress > backup.sql
```

**WordPress CLI**:
```bash
docker exec -it wordpress wp --allow-root user list
docker exec -it wordpress wp --allow-root plugin list
```

## Data Storage and Persistence

**Host locations**:
- MariaDB: `/home/$USER/data/mariadb/`
- WordPress: `/home/$USER/data/wordpress/`

**Container mount points**:
- MariaDB: `/var/lib/mysql/`
- WordPress/NGINX: `/var/www/html/`

**How it persists**: Bind mounts link host directories to containers. Data survives restarts and rebuilds.

**Management**:
```bash
# View data
ls -la /home/$USER/data/mariadb/

# Backup
tar -czf backup.tar.gz /home/$USER/data/

# Restore
tar -xzf backup.tar.gz -C /

# Clear (use make fclean instead)
sudo rm -rf /home/$USER/data/*
```

**Volumes**:
```bash
docker volume ls                    # List volumes
docker volume inspect srcs_mariadb_data
docker volume prune                 # Remove unused
```

## Debugging

**Check health**:
```bash
docker ps                           # Verify 3 containers running
docker exec mariadb mysqladmin ping -h localhost --silent
docker exec nginx nginx -t
```

**Common issues**:
```bash
# Port conflicts
sudo netstat -tlnp | grep -E ':80|:443'

# Rebuild without cache
docker compose -f srcs/docker-compose.yml build --no-cache

# Fix permissions
sudo chown -R $USER:$USER /home/$USER/data/
```

**Logs**:
```bash
docker compose -f srcs/docker-compose.yml logs
docker logs mariadb -f
```
