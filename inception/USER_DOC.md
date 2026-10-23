# User Documentation - Inception

## Services Provided

The stack provides a complete WordPress website with the following services:

- **NGINX**: Web server with HTTPS/TLS encryption (ports 80/443)
- **WordPress**: Content management system for creating and managing website content
- **MariaDB**: Database for storing WordPress data (posts, users, settings)

All services run in isolated Docker containers and communicate through a private network.

## Starting and Stopping the Project

### Start
```bash
make
```
This builds the Docker images (if needed) and starts all services in the background.

### Stop
```bash
make down
```
Stops all running containers. Data is preserved in `/home/$USER/data/`.

### Complete Reset
```bash
make fclean
```
⚠️ **Warning**: This stops containers, removes images, and **deletes all data** (database, uploaded files).

## Accessing the Website

### Website
- **URL**: `https://your-domain.42.fr` (replace with your configured domain)
- **Note**: HTTP (port 80) is disabled and returns a 405 error. Only HTTPS works.

### WordPress Admin Panel
1. Go to: `https://your-domain.42.fr/wp-admin`
2. Login with admin credentials (see Credentials section below)
3. From here you can:
   - Create/edit posts and pages
   - Manage users
   - Install themes and plugins
   - Configure site settings

## Managing Credentials

### Location
All credentials are stored in two places:

1. **Environment file**: `srcs/.env`
   - Domain name
   - Database name and user
   - WordPress admin and user accounts

2. **Secrets directory**: `secrets/`
   - `db_root_password.txt`: MariaDB root password
   - `db_password.txt`: MariaDB user password

### Default Users

After initial setup, you'll have two WordPress users:

| User Type | Username | Purpose |
|-----------|----------|---------|
| Administrator | From `WP_ADMIN_USER` | Full site control |
| Author | From `WP_USER` | Can create and publish posts |

### Changing Passwords

**WordPress passwords**: Change through the admin panel (Users → Profile)

**Database passwords**:
1. Edit the secret files in `secrets/`
2. Run `make fclean` then `make` (⚠️ destroys existing data)

## Checking Service Status

### Quick Check
```bash
docker ps
```
Should show 3 running containers: `nginx`, `wordpress`, `mariadb`

### Detailed Status
```bash
docker compose -f srcs/docker-compose.yml ps
```
All services should show `Up` status.

### View Logs
```bash
# All services
docker compose -f srcs/docker-compose.yml logs

# Specific service
docker compose -f srcs/docker-compose.yml logs nginx
docker compose -f srcs/docker-compose.yml logs wordpress
docker compose -f srcs/docker-compose.yml logs mariadb
```

### Health Check
```bash
# Check if MariaDB is responding
docker exec mariadb mysqladmin ping -h localhost --silent
echo $?  # Should return 0 if healthy
```

### Test Website Access
```bash
curl -k https://your-domain.42.fr
```
Should return HTML content (the WordPress homepage).

## Troubleshooting

**Containers won't start**:
- Check logs: `docker compose -f srcs/docker-compose.yml logs`
- Ensure ports 80 and 443 aren't in use: `sudo netstat -tlnp | grep -E ':80|:443'`

**Can't access website**:
- Verify all containers are running: `docker ps`
- Check domain in `/etc/hosts`: `127.0.0.1 your-domain.42.fr`
- Verify NGINX logs: `docker logs nginx`

**Database connection errors**:
- Wait 30 seconds after startup (MariaDB needs initialization time)
- Check MariaDB is healthy: `docker ps` (should show "healthy" status)
- Verify credentials match between `.env` and `secrets/`

**Data lost after restart**:
- Check volumes exist: `ls -la /home/$USER/data/`
- Permissions: `sudo chown -R $USER:$USER /home/$USER/data/`
