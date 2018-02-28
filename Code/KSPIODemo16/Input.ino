int input() {
  int returnValue = -1;
  now = millis();

  if (KSPBoardReceiveData()) {
    deadtimeOld = now;
    returnValue = id;
    switch (id) {
      case 0: // Handshake packet
        Handshake();
        break;
      case 1:
        Indicators();

        // -----------------------------------------------------------------------------------------
        if (TSN == 0)
        {TSN = VData.TotalStage;}
        displayFloat(lc,  0, (VData.CurrentStage/VData.TotalStage)*100);
        displayFloat(lc,  1, VData.CurrentStage/TSN);
        displayFloat(lc1, 0, VData.TotalStage);
        displayFloat(lc1, 1, VData.CurrentStage);
        displayFloat(lc2, 0, (VData.CurrentStage/TSN));
        displayFloat(lc2, 1, VData.CurrentStage);
        displayFloat(lc3, 0, TSN);
        displayFloat(lc3, 1, (VData.CurrentStage/TSN))
        // -----------------------------------------------------------------------------------------

        break;
    }

    // We got some data, turn the green led on
    digitalWrite(GLED, HIGH);
    Connected = true;
  } else { // if no message received for a while, go idle
    deadtime = now - deadtimeOld;
    if (deadtime > IDLETIMER) {
      deadtimeOld = now;
      Connected = false;
      LEDSAllOff();
    }
  }

  return returnValue;
}

byte ControlStatus(byte n) {
  return ((VData.ActionGroups >> n) & 1) == 1;
}

