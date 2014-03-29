
void cosm () //--------------- Envia dados para o cosm.com ------------------------------------
{
    if(ether.dnsLookup(website))
    {
      byte sd = stash.create();
      stash.print("A,"); // Temp. da água
      stash.println(tempC,DEC);
      stash.print("B,"); // Temp. dissipador
      stash.println(tempH,DEC);
      stash.print("C,"); // Temp. ambiente
      stash.println(tempA,DEC);
      stash.print("D,"); // PH do aquário
      stash.println(PHA, DEC);
      stash.print("E,"); // PH do reator de cálcio
      stash.println(PHR,DEC);
      stash.print("F,"); // Densidade
      stash.println(DEN);
      stash.print("G,"); // ORP
      stash.println(ORP);
      stash.print("H,"); // Status chiller, 0 = desligado e 1 = ligado
      stash.println(bitRead(status_parametros,0));
      stash.print("I,"); // Status aquecedor, 0 = desligado e 1 = ligado
      stash.println(bitRead(status_parametros,1));
      stash.print("J,"); // Status reator de cálcio, 0 = desligado e 1 = ligado
      stash.println(bitRead(status_parametros,5));
      stash.print("K,"); // Status ozonizador, 0 = desligado e 1 = ligado
      stash.println(bitRead(status_parametros,7));
      stash.print("L,"); // Status reposição de água doce, 0 = desligado e 1 = ligado
      stash.println(bitRead(Status,1));
      stash.print("M,"); // Status niveis, 0 = baixo e 1 = normal
      stash.println(nivel_status);
      stash.print("N,"); // Status TPA, 0 = desligado e 1 = ligado
      stash.println(bitRead(tpa_status,0));
      stash.print("O,"); // Potência dos leds azuis
      stash.println(LedToPercent(bled_out));
      stash.print("P,"); //Potência dos leds brancos
      stash.println(LedToPercent(wled_out));
      stash.print("Q,"); // Potência dos leds azul royal
      stash.println(LedToPercent(rbled_out));
      stash.print("R,"); //Potência dos leds vermelhos
      stash.println(LedToPercent(rled_out));
      stash.print("S,"); //Potência dos leds violeta
      stash.println(LedToPercent(uvled_out));
      stash.print("T,"); 
      stash.println(bitRead(temporizador_status,1)); // Status timer 1, 0 = desligado e 1 = ligado
      stash.print("U,"); 
      stash.println(bitRead(temporizador_status,2)); // Status timer 2, 0 = desligado e 1 = ligado
      stash.print("V,");
      stash.println(bitRead(temporizador_status,3)); // Status timer 3, 0 = desligado e 1 = ligado
      stash.print("W,"); 
      stash.println(bitRead(temporizador_status,4)); // Status timer 4, 0 = desligado e 1 = ligado
      stash.print("X,"); 
      stash.println(bitRead(temporizador_status,5)); // Status timer 5, 0 = desligado e 1 = ligado
      stash.print("Y,"); // Potência Real
      stash.println((millis()/1000)/60);
      stash.print("Z,"); // Potência aparente
      stash.println((millis()/1000)/60);
      stash.print("ZA,"); // Fator de potência
      stash.println((millis()/1000)/60);
      stash.print("ZB,"); // Tensão RMS
      stash.println((millis()/1000)/60);
      stash.print("ZC,"); // Corrente RMS
      stash.println((millis()/1000)/60);
      stash.print("ZD,"); // Frequência
      stash.println((millis()/1000)/60);
      stash.print("ZE,"); // KWh
      stash.println((millis()/1000)/60); 
      stash.print("ZF,"); // Sinaliza falha na TPA
      stash.println(bitRead(tpa_status,2));      
      stash.save();
       // Gerar o cabeçalho com carga útil - note que o tamanho do "stash" é usado,
       // E que um "stash descriptor" é passado como argumento usando "$ H".
      Stash::prepare(PSTR("PUT http://$F/v2/feeds/$F.csv HTTP/1.0" "\r\n"
        "Host: $F" "\r\n"
        "X-PachubeApiKey: $F" "\r\n"
        "Content-Length: $D" "\r\n"
        "\r\n"
        "$H"),
      website, PSTR(FEED), website, PSTR(APIKEY), stash.size(), sd);

    // Envia o pacote - este também libera todos os "stash buffers", uma vez feito.
      ether.tcpSend();
    }
}
