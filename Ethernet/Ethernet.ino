#include <SPI.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>

byte mac[]={0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,30,182);

EthernetServer server(80);


#define RED_PORT 3

boolean statusLED = false; //LED상태
String buffer = ""; //수신 데이터 버퍼


void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac,ip);

  Serial.println("WebServerControlLED");
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  //서버 연결 시작
  server.begin();
  delay(2000);

  pinMode(RED_PORT, OUTPUT);
  digitalWrite(RED_PORT,LOW);


}

void loop() {
  EthernetClient client = server.available();
  if(client){
    int response_type= -1;
    Serial.println("** New client connected...**");

    while(client.connected()){
      boolean empty_line = read_one_line(client);
      Serial.println(buffer);
      if(buffer.indexOf("GET / ")>=0){
        response_type=1;    //메인 페이지 요청
      }else if(buffer.indexOf("GET /led.cgi?LEDstatus=1")>=0){
        response_type=2;    //LED ON 페이지 요청
      }else if(buffer.indexOf("GET /led.cgi?LEDstatus=0")>=0){
        response_type=3;    //LED OFF 페이지 요청
      }
      if(empty_line){ break; }

    }

    switch(response_type){
      case 1:
        show_main_page(client);
        break;
      case 2:
        show_on_off_page(client,true);
        break;
      case 3:
        show_on_off_page(client,false);
        break;
    }

    client.stop();    //웹브라우저 연결 종료
    Serial.println("** client disconnected **");

  }else{
    Serial.print("연결 안됬다.");
  }
}

boolean read_one_line(EthernetClient client){
  buffer="";    //버퍼 비움
  while(client.available() ){
    char c = client.read();   //바이트 데이터 읽기

    if(c == '\r'){    //'\r'은 개행문자이다. //개행문자를 수신한 경우
      client.read();
      break;
    }

    buffer = buffer + c;  //개행 문자 이외의 문자를 버퍼에 저장
  }

  return (buffer.length()== 0);

}

void show_main_page(EthernetClient client){
  //HTML 헤더
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();

  //HTML 내용
  client.println("<html>");
  client.println("<body><script>");
  client.println("alert('Currently... LED is ");
  client.println(statusLED ? "ON.');": "OFF.');" );
  client.println("</script></body>");
  client.println("</html>");
  
}

void show_on_off_page(EthernetClient client, boolean status){
  statusLED = status;   //LED 상태 저장
  digitalWrite(RED_PORT, status);   //status값이 true이면 불이 켜지고, false이면 불이 꺼진다.

  String str = "LED 상태 : ";
  Serial.println(str +( status ? "HIGH" : "LOW" ));

  //HTML 헤더
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();

  //HTML 내용
  client.println("<html>");
  client.println("<body><script>");
  client.println("alert('Currently... LED is ");
  client.println(statusLED ? "ON.');": "OFF.');" );
  client.println("</script></body>");
  client.println("</html>");
  
}
