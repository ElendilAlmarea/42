<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', '172.17.0.2' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '|j*]6eUpG~H~[sG+|507UE3L$af1|ma-`J[#};/oFP.yvivT67D`c*2t-dn8nrbv' );
define( 'SECURE_AUTH_KEY',  'Zt1q|eAyqQUxw>r7TO.M+-?e|%g<x2^gk&vUz|)G}t]kRQ~Mbr%psXJ8=XjYP(iD' );
define( 'LOGGED_IN_KEY',    'A]l|N@-%}S]irkH-R]QMPZd<fN{eNMm|D|fA`!#m/Fw &+tZ< TH_/f8z,jG]@pp' );
define( 'NONCE_KEY',        'V*Fb*9M}Vbo|+pG.GhUb1rt9U4Ar!c)-kBWqVaGY`ti{09N^pAD VU}ngp<G@9HW' );
define( 'AUTH_SALT',        'h0@P)s;.4ID-[]uPye@Wg@YDjT5E^,,}82) {R=c86^b`2>11;@L3p^Zf3r?K580' );
define( 'SECURE_AUTH_SALT', 'wW7`lPU@sGG6E#%XzGK_t>$09VZAF0x;lZgwQ#bPfr6,P-w|PEHTxXa*W[Zp{M+:' );
define( 'LOGGED_IN_SALT',   '#/&kYO_ew2uK)^XTR(t}7gnf+T7(50Lk10q?K@B=}/$hR sBJ4=a??K?X&=1d,pq' );
define( 'NONCE_SALT',       'qB^<,+:?OBbndh=3gDj|_sH:K|+35(s|q37C76HEKZ*[ [dpT!|[@6s!m+CITqf.' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
