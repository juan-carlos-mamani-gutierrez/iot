
// TODO Genera un log personalizado en el puerto Serial
// type: INFO, WARNING, DANGER
// msg: Mensaje

void log(String type, String msg){ // [INFO] demo
    Serial.println("[" + type + "] " + msg);
}

// TODO Definir la Plataforma
// Optiene la plataforma de hardware

String platform(){
#ifdef ARDUINO_ESP32_DEV
    return "ESP32";
#endif
}
// TODO De HEX a String
String HexToStr(const unsigned long &h, const byte &l){
    String s;
    s = String(h, HEX);
    s.toUpperCase();
    s = ("00000000" + s).substring(s.length() + 8 - l);
    return s;
}
// TODO Crear un ID unico desde la direccion MAC
// Retorna los ultimos 4 Bytes del MAC rotados
String UniqueID(){    
    char uniqueid[15]; 
    uint64_t chipid = ESP.getEfuseMac();           
    uint16_t chip = (uint16_t)(chipid >> 32);
    snprintf(uniqueid, 15, "%04X", chip);
    return uniqueid;
}
// TODO Número de serie del Dispositivo único => ESP329B1C52100C3D
String DeviceID(){
    return String(platform())+ HexToStr(ESP.getEfuseMac(),8) + String(UniqueID());
}
// TODO Quitar numeros de la cadena
String extractNumbers(String e){
    String inputString = e;
    inputString.toLowerCase();
    String outString = "";
    int len = inputString.length();
    for (size_t i = 0; i < len; i++)
    {
        if (!isDigit((char)inputString[i]))
        {
            outString += (char)inputString[i];
        }       
    }
    return outString;
}
// TODO Crear un path para los Topicos en MQTT
// emqx/ESP329B1C52100C3D/#   +/# = > usuario/id/# => emqx/ESP329B1C52100C3D/status = true/false
String PathMqttTopic(String topic){
    return String(String(mqtt_user)+"/"+String(mqtt_id)+"/"+topic);
}