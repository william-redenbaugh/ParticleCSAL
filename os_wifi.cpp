#include "global_includes.h"
#include "Particle.h"

#define DEBUG_WIFI

#ifdef DEBUG_WIFI
#define wifi_println(e)       println(e)
#define wifi_print(e)         print(e)
#define wifi_printf(e, ...)   printf(e)
#endif

int os_wifi_connect_sta(char *ssid, char *password) {
  

  return OS_RET_OK;
}

int os_wifi_disconnect_sta() {
  Particle.disconnect();
  return OS_RET_OK;
}

os_udp_server_t *os_wifi_setup_udp_server(int port) {
  
  os_udp_server_t *udp_server =  new os_udp_server_t; 
  udp_server->udp.begin(port);
  return udp_server;
}

int os_wifi_deconstruct_udp_server(os_udp_server_t *udp){
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }
  udp->udp.flush_buffer();
  udp->udp.stop();
  
  // Don't use the pointer after free!!!
  free(udp);
  return OS_RET_OK;
}

int os_wifi_start_udp_transmission(os_udp_server_t *udp, char *ip, uint16_t port) {
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  if(udp->udp.beginPacket(ip, port) < 0){
    return OS_RET_INT_ERR;
  }
  return OS_RET_OK;
}

int os_wifi_stop_udp_transmission(os_udp_server_t *udp) {
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  if(udp->udp.endPacket() < 0){
    return OS_RET_INT_ERR;
  }
  return OS_RET_OK;
}

int os_wifi_transmit_udp_packet(os_udp_server_t *udp, uint16_t packet_size, uint8_t *arr) {
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }
  udp->udp.write(arr, packet_size);
  return OS_RET_OK;
}

static inline int read_packet(os_udp_server_t *udp, uint16_t *packet_size, uint8_t *arr){
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }
  *packet_size = udp->udp.readBytes((char*)arr, *packet_size);
  return OS_RET_OK;;
}

int os_wifi_receive_packet(os_udp_server_t *udp, uint16_t *packet_size, uint8_t *arr, uint32_t timeout_ms) {
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  return read_packet(udp, packet_size, arr);
}

int os_wifi_receive_packet_indefinite(os_udp_server_t *udp, uint16_t *packet_size, uint8_t *arr){
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  return read_packet(udp, packet_size, arr);
}