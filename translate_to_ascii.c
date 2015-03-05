unsigned int translate_to_ascii(struct usb_keyboard_packet packet){
	/* a-z or A-Z */
	if (packet.keycode[0] >= 4 && packet.keycode[0] <= 29){
		if (packet.modifiers == 2 || packet.modifiers == 32 || packet.modifiers == 34){
			return packet.keycode[0] + 61;
		}else{
			return packet.keycode[0] + 93;
		}
	}
	/* numbers */
	if (packet.keycode[0] >= 30 && packet.keycode[0] <= 39){
		if (packet.modifiers == 2 || packet.modifiers == 32 || packet.modifiers == 34){
			return translate0[((int)packet.keycode[0]) - 30];
		}else{
			if(packet.keycode[0] == 39)
				return packet.keycode[0]+9;
			else
				return packet.keycode[0] + 19;
		}
	}
	/* SPACEBAR */
	if (packet.keycode[0] == 44 ){
		return 32;
	}
	return 0;
}
