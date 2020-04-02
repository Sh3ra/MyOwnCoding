<?php

class Connect {
	public function connection(){
		return new mysqli(HOST,USER,PASSWORD,DB_NAME);
	}
}