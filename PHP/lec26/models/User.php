<?php 
define("HOST","localhost");
define("USER","root");
define("PASSWORD","");
define("DB_NAME","twitter");

class Connect {
	static public function connectionToDb(){
		$mysqli_object = new mysqli(HOST,USER,PASSWORD,DB_NAME); 
		return $mysqli_object;
	}
}

class BaseEntity {
	 protected  $connection ;
		
	public function __construct(){
		
		$this->connection = Connect::connectionToDb();
		/* check connection */
		if ($this->connection->connect_errno) {
			printf("Connect failed: %s\n", $this->connection->connect_error);
			exit();
		}
	}

    public function __call($methodName, $args){
		
        if(preg_match('~^(set|get)([A-Z])(.*)$~', $methodName, $matches))
        {
            $property = strtolower($matches[2]) . $matches[3];
            if(!property_exists($this, $property))
            {
                throw new \Exception('Property ' . $property . ' not exists');
            }
            switch ($matches[1])
            {
                case 'set':
                    $this->checkArguments($args, 1, 1, $methodName);
                    return $this->set($property, $args[0]);
                case 'get':
                    $this->checkArguments($args, 0, 0, $methodName);
                    return $this->get($property);
                case 'default':
                    throw new \Exception('Method ' . $methodName . ' not exists');
            }
        }
    }
	


  
	public function get($property){
        return $this->$property;
    }

    public function set($property, $value){
        $this->$property = $value;
        return $this;
    }

    protected function checkArguments(array $args, $min, $max, $methodName){
        $argc = count($args);
        if($argc < $min || $argc > $max)
        {
            throw new \Exception('Method ' . $methodName . ' needs minimaly ' . $min . ' and maximaly ' . $max . ' arguments. ' . $argc . ' arguments given.');
        }
    }

}

class User extends BaseEntity {
	
	protected  $name ; 
	protected  $id;
	protected  $dob; 
	protected  $password;
	protected  $email;
	protected  $phone;
	protected  $friends ; 
	protected  $tweet ;
	
	public function __construct(int $id = 0 ){
		parent::__construct();
		if($id){
			$user = $this->connection->query("SELECT * FROM users WHERE id = $id ");
			
			if($user->num_rows) {
				$user_data = $user->fetch_assoc();
				foreach($user_data as $key => $val ) {
					$this->$key = $val ;
				}
			}			
		}
	} 
	

	public  function is_email() :bool{
		return $this->connection->query("SELECT email FROM users WHERE email= '".$this->email."'")->num_rows? true : false ; 
	}
	public function getAge(){
		$age = 0 ;
		
		return $age ;
	}
	public function addFriend($user){
		$this->conncetion->query() ;
		$this->friends[] = $user ; 
	}
	public function save(){
		if($this->connection->query("INSERT INTO users SET name = '".$this->name."', email = '".$this->email."'"))
			$this->id = $this->connection->insert_id;
		else
			$this->connection->error;
	}
	public function update(){
		if($this->connection->query("UPDATE users SET name = '".$this->name."', email = '".$this->email."' WHERE id = ".$this->id.""))
			return true ;
		else
			$this->connection->error;
	}
	public function destroy() {
		if($this->connection->query("DELETE FROM users WHERE id = ".$this->id.""))
			return true ;
		else
			$this->connection->error;
	}
};



