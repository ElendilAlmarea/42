<?php
/**
 * The base configuration for WordPress
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 * @package WordPress
 */
// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wordpress');
/** MySQL database username */
define('DB_USER', 'root');
/** MySQL database password */
define('DB_PASSWORD', '');
/** MySQL hostname */
define('DB_HOST', 'localhost');
/** Charset for database tables. */
define('DB_CHARSET', 'utf8');
/** The Database Collate type. mysql auto-assigns it if blank */
define('DB_COLLATE', '');

/* Authentication Unique Keys and Salts.
 * You can change these at any point in time to invalidate all existing cookies.
 * Just put random and long keys */
define('AUTH_KEY',         'GAHh@5K.Et5ynvUXAwlG>@Q<B:i}E&pAnDM}2oI*w-[8MQx/!o2=+a>pF*|kprW&');
define('SECURE_AUTH_KEY',  'k >z;DPz>`1Cy.;*s,Kk)HlgwR-[C(uacTbOboFIRyc*q*_|?Mlw-*{%aTNhk$If');
define('LOGGED_IN_KEY',    '4-.h@7US(>+)#W_L][h^0_%Q-m#~?HjI{0W^z9&BmSN.+#.WzaB+CE2Dls+2|d,|');
define('NONCE_KEY',        'g/FY$RgkMLcC5NNCm@]&iD<f.|DZ9&^FBI;b//|;ZW(C]J-fEZZq YMLD/AbTOmr');
define('AUTH_SALT',        'Lp+6=+p^`KI4s9dpC{8 !vy],%+-=,+i#?2~s$>myBzJ!@{WcR@*V<&YH=/{btb@');
define('SECURE_AUTH_SALT', 'c$ Y#6s4z~&;_h0~,[V:F4XhxWoPk8)v*5l%|-E!PTX6^366xL7eh1A$F>Pi?>V0');
define('LOGGED_IN_SALT',   'Rmuo6WwVlpqC_>Cq<r01-:mJs+8QgI;$<O=os^C9}M9DTd^XX7(Y7-_yc7,#>kWa');
define('NONCE_SALT',       'ijK{HD+(gH1)*@v!U|8`Ip^b-`?mkbS-`9Npv+4bbJ>d&</Os`<w/F-u4<J|8{fL');

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/** Absolute path to the WordPress directory. */
if (!defined('ABSPATH')) {
	define('ABSPATH', dirname( __FILE__ ).'/');
}
/** Set up */
require_once(ABSPATH.'wp-settings.php');
?>