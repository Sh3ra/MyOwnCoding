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

class Image extends BaseEntity {
	
	protected $id ; 
	protected $path ; 
	
	public function all(){
		$images = [] ; 
		$image_query = $this->connection->query("SELECT id FROM images");
		if( $image_query->num_rows ) 
			while ( $image = $image_query->fetch_assoc() ) 
				$images[] = new Image($image['id']) ;
		return $images ;
	}
	
	public function __construct(int $id = 0 ){
		parent::__construct();
		if($id){
			$image = $this->connection->query("SELECT * FROM images WHERE id = $id ");
			if($user->num_rows) {
				$user_data = $user->fetch_assoc();
				foreach($user_data as $key => $val ) {
					$this->$key = $val ;
				}
			}
		}
	} 
	public function save(){
		if($this->connection->query("INSERT INTO images SET path = '".$this->path."'"))
			$this->id = $this->connection->insert_id;
		else
			$this->connection->error;
	}
	public function update(){
		if($this->connection->query("UPDATE images SET path = '".$this->path."'"))
			return true ;
		else
			$this->connection->error;
	}
	public function destroy() {
		if($this->connection->query("DELETE FROM images WHERE id = ".$this->id.""))
			return true ;
		else
			$this->connection->error;
	}
	public function getImage(){
		return " <img src='".$this->path."' />";
	}
	
	};



