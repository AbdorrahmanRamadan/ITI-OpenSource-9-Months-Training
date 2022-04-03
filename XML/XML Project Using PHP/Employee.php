<?php
class Employee
{
    public $form_name='';
    public $form_phone='';
    public $form_street='';
    public $form_building='';
    public $form_region='';
    public $form_city='';
    public $form_country='';
    public $form_email='';
    function getEmployee($id){
        $_xml = simplexml_load_file('employees_data.xml');
        $Emp=$_xml->Employee[$id];
        $this->form_name=$Emp->name;
        $this->form_phone=$Emp->phones->phone;
        $this->form_street=$Emp->addresses->address->street;
        $this->form_building=$Emp->addresses->address->building;
        $this->form_region=$Emp->addresses->address->region;
        $this->form_city=$Emp->addresses->address->city;
        $this->form_country=$Emp->addresses->address->country;
        $this->form_email=$Emp->email;
    }
    function update($employees,$emp_name, $emp_phone, $emp_street, $emp_building,$emp_region,$emp_city,$emp_country, $email){
                $emp=$employees->Employee[$_SESSION['count']];
                $emp->name = $emp_name;
                $emp->phones->phone= $emp_phone;
                $emp->addresses->address->street= $emp_street;
                $emp->addresses->address->building= $emp_building;
                $emp->addresses->address->region= $emp_region;
                $emp->addresses->address->city= $emp_city;
                $emp->addresses->address->country= $emp_country;
                $emp->email = $email;

        file_put_contents('employees_data.xml', $employees->asXML());
    }
    function delete($employees, $emp_name){
        foreach ($employees->Employee as $emp){
            if ($emp->name == $emp_name){
                $dom=dom_import_simplexml($emp);
                $dom->parentNode->removeChild($dom);
            }
        }
        file_put_contents('employees_data.xml', $employees->asXML());
    }
    function insert($employees,$emp_name, $emp_phone, $emp_street, $emp_building,$emp_region,$emp_city,$emp_country, $email){
        $emp = $employees->addChild('Employee');
        $emp->addChild('name', $emp_name);
        $phones = $emp->addChild('phones');
        $phones->addChild('phone', $emp_phone);
        $addresses = $emp->addChild('addresses');
        $address = $addresses->addChild('address');
        $address->addChild('street',$emp_street);
        $address->addChild('building',$emp_building);
        $address->addChild('region',$emp_region);
        $address->addChild('city',$emp_city);
        $address->addChild('country',$emp_country);
        $emp->addChild('email', $email);
        file_put_contents('employees_data.xml', $employees->asXML());
    }
    function search($employees, $emp_name){
        $position = 0;
        foreach ($employees->Employee as $emp){
            if ($emp->name != $emp_name){
                $position ++;
            }else{
                return $position;
            }
        }
        return $position;
    }
}