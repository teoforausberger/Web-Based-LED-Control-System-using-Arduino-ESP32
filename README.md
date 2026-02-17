# Proiect -- Sistem WiFi Control (Arduino / ESP)

Acest proiect implementează un sistem bazat pe microcontroler
(ESP8266/ESP32) care utilizează conectivitatea WiFi pentru control și
comunicare în rețea. Dispozitivul se conectează la o rețea wireless și
permite interacțiunea prin intermediul unui server web.

Proiectul demonstrează: - Conectarea la o rețea WiFi - Inițializarea
unui server web - Gestionarea cererilor client - Controlul unor ieșiri
hardware (ex: LED)

------------------------------------------------------------------------

# Tehnologii utilizate

-   Arduino IDE
-   ESP8266 / ESP32
-   Limbaj: C++ (Arduino framework)
-   Protocol: HTTP
-   Comunicare: WiFi

------------------------------------------------------------------------

# Structura proiectului

-   Cod_WiFi.ino → Codul principal al aplicației
-   Video_functionare.mp4 → Demonstrarea funcționării sistemului
-   README.md → Documentația proiectului

------------------------------------------------------------------------

# Funcționalitate

1.  Dispozitivul pornește și inițializează conexiunea WiFi.
2.  Se conectează la rețeaua specificată în cod (SSID + parolă).
3.  Pornește un server web pe o adresă IP locală.
4.  Permite accesarea unei pagini web pentru control hardware.

------------------------------------------------------------------------

# Instalare și rulare

1.  Instalează Arduino IDE.

2.  Instalează suport pentru placa ESP din Boards Manager.

3.  Deschide fișierul Cod_WiFi.ino.

4.  Modifică în cod:

    const char\* ssid = "NUME_RETEA"; const char\* password = "PAROLA";

5.  Selectează placa și portul corect.

6.  Încarcă programul pe microcontroler.

7.  Deschide Serial Monitor pentru a vedea IP-ul alocat.

------------------------------------------------------------------------

# Demonstrație

Funcționarea proiectului este prezentată în fișierul:
Video_functionare.mp4

------------------------------------------------------------------------

# Posibile îmbunătățiri

-   Implementare autentificare utilizator
-   Interfață web mai complexă (HTML + CSS)
-   Control prin aplicație mobilă
-   Integrare IoT (MQTT)
-   Salvare date în EEPROM

------------------------------------------------------------------------

# Autor

Proiect realizat pentru demonstrarea utilizării conectivității WiFi
într-un sistem embedded.
