// TODO los pines que vamos a usar
#define RELAY1 32    //GPIO32 para salida de Relay 1
#define RELAY2 33    //GPIO33  para la salida de Relay 2
#define WIFILED 26   //GPIO26 led indicador WIFI
#define MQTTLED 27   //GPIO27 led indicador MQTT
#define DIMMER 25    //GPIO25 led indicador DIMMER

#define TEXTIFY(A) #A
#define ESCAPEQUOTE(A) TEXTIFY(A)
String device_fw_version = ESCAPEQUOTE(BUILD_TAG);
// TODO version de hardware y fabricante
#define device_hw_version "ADMINESP32 v1 00000000" //version del hardware
#define device_manufacturer "DRAGO"
// TODO zona  configuracion dispositivo
char device_id[30];          //id del dispositivo
char device_name[30];        //nombre del dispositivo
int  device_restart;         //numero del reinicio
char device_user[15];        //usuario para acceso al servidot web
char device_password[15];    //Contrasena del usuario servidor web
// TODO zona configuracion WIFI modo cliente
int     wifi_app = WIFI_AP;      // WIFI modo WIFI_AP & WIFI_STA
boolean wifi_mode;               // Uso de Modo AP false o Cliente true
char    wifi_ssid[63];           // Nombre de la red WiFi a conectar                
char    wifi_password[63];       // Contraseña de la Red WiFi a conectar
boolean wifi_ip_static;          // Uso de IP Estática DHCP true estática false DHCP
char    wifi_ipv4[16];           // Dir IPv4 Estático 
char    wifi_gateway[16];        // Dir IPv4 Gateway     
char    wifi_subnet[16];         // Dir IPv4 Subred    
char    wifi_dns_primary[16];    // Dir IPv4 DNS primario  
char    wifi_dns_secondary[16];  // Dir IPv4 DNS secundario 
// TODO  zona configuracion WIFI modo AP
char ap_ssid[63];       // Nombre del SSID modo AP máximo 63     
char ap_password[63];   // Contraseña del modo AP mínimo 8 NULL red abierta
int  ap_chanel;         // Canal AP 1-13      
int  ap_visibility;     // Es visible o no el AP  (0 - Visible  1 - Oculto)  
int  ap_connect;        // Número de conexiones en el AP máx 8 conexiones ESP32
//TODO Zona configuración MQTT 
boolean mqtt_enable;           // Habilitar MQTT Broker true / false
char    mqtt_server[39];       // Servidor del MQTT Broker
int     mqtt_port;             // Puerto servidor MQTT Broker 1883 / 8883
boolean mqtt_retain;           // Habilitar mensajes retenidos
int     mqtt_qos;              // Calidad del servicio 0,1,2
char    mqtt_id[30];           // Cliente ID MQTT Broker       
char    mqtt_user[30];         // Usuario MQTT Broker 
char    mqtt_password[39];     // Contraseña del MQTT Broker
boolean mqtt_clean_sessions;   // Habilitar sesiones limpias
char    mqtt_willTopic[150];   // Will topico
char    mqtt_willMessage[63];  // Will mensaje
int     mqtt_willQoS;          // Will calidad de servicio 0,1,2
boolean mqtt_willRetain;       // Will mensaje retenido
boolean mqtt_time_send;        // Habilitar en envio de datos
int     mqtt_time_interval;    // Tiempo de envio por MQTT en segundos
boolean mqtt_status_send;      // Habilitar en envio de estados
//TODO zona EEPROM para contador  de reinicios
#define Start_Address 0                                 // Posición de inicio en la EEPROM
#define Restart_Address Start_Address + sizeof(int)     // Dirección del dato en la EEPROM
//TODO zona  otras
float temp_cpu; // Temperatura del CPU en °C
//TODO zona de RELAY
bool RELAY1_STATUS; // GPIO32 Estado del pin
bool RELAY2_STATUS; // GPIO33 Estado del pin
//TODO zona PW
const int freq = 1000;     // frecuencia de trabajo 1kHz
const int ledChannel = 0;  // definicion del canal
const int resolution = 8;  // 255
int       dim;             // valor del dimmer a enviar