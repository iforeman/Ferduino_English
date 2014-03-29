void check_temporizadores()
{

  if ((temporizador_1_ativado == 1) && (bitRead(temporizador_modificado,1) == false))
  {  
   if(NumMins(off1_hora,off1_minuto) > NumMins(on1_hora,on1_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on1_hora,on1_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off1_hora,off1_minuto)))
    {
      digitalWrite(temporizador1, HIGH);
      bitWrite(temporizador_status,1,1);
    }
    if (NumMins(t.hour,t.min) > NumMins(off1_hora,off1_minuto))
    {
      digitalWrite(temporizador1, LOW);
      bitWrite(temporizador_status,1,0);
    }
   }
   if(NumMins(off1_hora,off1_minuto) < NumMins(on1_hora,on1_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on1_hora,on1_minuto)) 
    {
      digitalWrite(temporizador1, HIGH);
      bitWrite(temporizador_status,1,1);
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off1_hora,off1_minuto)) 
    {
      digitalWrite(temporizador1, HIGH);
      bitWrite(temporizador_status,1,1);
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off1_hora,off1_minuto)) && (NumMins(t.hour,t.min) < NumMins(on1_hora,on1_minuto)))
    {
      digitalWrite(temporizador1, LOW);
      bitWrite(temporizador_status,1,0);
    } 
   }
  }
  else
  {
    digitalWrite(temporizador1, LOW);
    bitWrite(temporizador_status,1,0);
    bitWrite(temporizador_modificado,1,0);
  }
  if ((temporizador_2_ativado == 1)  && (bitRead(temporizador_modificado,2) == false))
  {
   if(NumMins(off2_hora,off2_minuto) > NumMins(on2_hora,on2_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on2_hora,on2_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off2_hora,off2_minuto)))
    {
      digitalWrite(temporizador2, HIGH);
      bitWrite(temporizador_status,2,1);
    }
    if (NumMins(t.hour,t.min) > NumMins(off2_hora,off2_minuto))
    {
      digitalWrite(temporizador2, LOW);
      bitWrite(temporizador_status,2,0);
    }
   }
   if(NumMins(off2_hora,off2_minuto) < NumMins(on2_hora,on2_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on2_hora,on2_minuto)) 
    {
      digitalWrite(temporizador2, HIGH);
      bitWrite(temporizador_status,2,1);
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off2_hora,off2_minuto)) 
    {
      digitalWrite(temporizador2, HIGH);
      bitWrite(temporizador_status,2,1);
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off2_hora,off2_minuto)) && (NumMins(t.hour,t.min) < NumMins(on2_hora,on2_minuto)))
    {
      digitalWrite(temporizador2, LOW);
      bitWrite(temporizador_status,2,0);
    } 
   }
  }
  else
  {
    digitalWrite(temporizador2, LOW);
    bitWrite(temporizador_status,2,0);
    bitWrite(temporizador_modificado,2,0);
  }  
  if ((temporizador_3_ativado == 1) && (bitRead(temporizador_modificado,3) == false)) 
  {  
   if(NumMins(off3_hora,off3_minuto) > NumMins(on3_hora,on3_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on3_hora,on3_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off3_hora,off3_minuto)))
    {
      digitalWrite(temporizador3, HIGH);
      bitWrite(temporizador_status,3,1);
    }
    if (NumMins(t.hour,t.min) > NumMins(off3_hora,off3_minuto))
    {
      digitalWrite(temporizador3, LOW);
      bitWrite(temporizador_status,3,0);
    }
   }
   if(NumMins(off3_hora,off3_minuto) < NumMins(on3_hora,on3_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on3_hora,on3_minuto)) 
    {
      digitalWrite(temporizador3, HIGH);
      bitWrite(temporizador_status,3,1);
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off3_hora,off3_minuto)) 
    {
      digitalWrite(temporizador3, HIGH);
      bitWrite(temporizador_status,3,1);
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off3_hora,off3_minuto)) && (NumMins(t.hour,t.min) < NumMins(on3_hora,on3_minuto)))
    {
      digitalWrite(temporizador3, LOW);
      bitWrite(temporizador_status,3,0);
    } 
   }
  }
  else
  {
    digitalWrite(temporizador3, LOW);
    bitWrite(temporizador_status,3,0);
    bitWrite(temporizador_modificado,3,0);  
  } 
  if ((temporizador_4_ativado == 1) && (bitRead(temporizador_modificado,4) == false)) 
  {  
   if(NumMins(off4_hora,off4_minuto) > NumMins(on4_hora,on4_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on4_hora,on4_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off4_hora,off4_minuto)))
    {
      digitalWrite(temporizador4, HIGH);
      bitWrite(temporizador_status,4,1);
    }
    if (NumMins(t.hour,t.min) > NumMins(off4_hora,off4_minuto))
    {
      digitalWrite(temporizador4, LOW);
      bitWrite(temporizador_status,4,0);
    }
   }
   if(NumMins(off4_hora,off4_minuto) < NumMins(on4_hora,on4_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on4_hora,on4_minuto)) 
    {
      digitalWrite(temporizador4, HIGH);
      bitWrite(temporizador_status,4,1);
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off4_hora,off4_minuto)) 
    {
      digitalWrite(temporizador4, HIGH);
      bitWrite(temporizador_status,4,1);
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off4_hora,off4_minuto)) && (NumMins(t.hour,t.min) < NumMins(on4_hora,on4_minuto)))
    {
      digitalWrite(temporizador4, LOW);
      bitWrite(temporizador_status,4,0);
    } 
   }
  }
  else
  {
    digitalWrite(temporizador4, LOW);
    bitWrite(temporizador_status,4,0);
    bitWrite(temporizador_modificado,4,0);   
  }
  if ((temporizador_5_ativado == 1) && (bitRead(temporizador_modificado,5) == false))
  {  
   if(NumMins(off5_hora,off5_minuto) > NumMins(on5_hora,on5_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on5_hora,on5_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off5_hora,off5_minuto)))
    {
      digitalWrite(temporizador5, HIGH);
      bitWrite(temporizador_status,5,1);
    }
    if (NumMins(t.hour,t.min) > NumMins(off5_hora,off5_minuto))
    {
      digitalWrite(temporizador5, LOW);
      bitWrite(temporizador_status,5,0);
    }
   }
   if(NumMins(off5_hora,off5_minuto) < NumMins(on5_hora,on5_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on5_hora,on5_minuto)) 
    {
      digitalWrite(temporizador5, HIGH);
      bitWrite(temporizador_status,5,1);
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off5_hora,off5_minuto)) 
    {
      digitalWrite(temporizador5, HIGH);
      bitWrite(temporizador_status,5,1);
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off5_hora,off5_minuto)) && (NumMins(t.hour,t.min) < NumMins(on5_hora,on5_minuto)))
    {
      digitalWrite(temporizador5, LOW);
      bitWrite(temporizador_status,5,0);
    } 
   }
  }
  else
  {
    digitalWrite(temporizador5, LOW);
    bitWrite(temporizador_status,5,0);
     bitWrite(temporizador_modificado,5,0);
  }  
}

