<?php
require_once ('Employee.php');
session_start();
if(!isset($_SESSION['count'])){
    $_SESSION['count']=0;
}
$xml_file = simplexml_load_file("employees_data.xml");
$employee = new Employee();

if (isset($_POST['Insert'])) {
    $employee->insert($xml_file, $_POST['name'], $_POST['phone'], $_POST['street'], $_POST['building'], $_POST['region'], $_POST['city'], $_POST['country'], $_POST['email']);
}
if (isset($_POST['Update'])) {
    $employee->update($xml_file, $_POST['name'], $_POST['phone'], $_POST['street'], $_POST['building'], $_POST['region'], $_POST['city'], $_POST['country'], $_POST['email']);
}
if (isset($_POST['Delete'])) {
    $employee->delete($xml_file, $_POST['name']);
}
if (isset($_POST['Search'])) {
    $_SESSION['count'] = $employee->search($xml_file, $_POST['name']);
    $employee->getEmployee($_SESSION['count']);
}
if (isset($_POST['Previous'])) {
    if ($_SESSION['count'] > 0) {
        $_SESSION['count']--;
    } else {
        $_SESSION['count'] = count($xml_file->Employee) - 1;
    }
    $employee->getEmployee($_SESSION['count']);
}
if (isset($_POST['Next'])) {
    if($_SESSION['count'] < count($xml_file->Employee)-1)
    {
        $_SESSION['count']++;
    } else{
        $_SESSION['count'] = 0;
    }
    $employee->getEmployee($_SESSION['count']);
}
?>
<!DOCTYPE html>
<html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<img class="top_left_corner" src="Path%201.svg">
<img class="bottom_right_corner" src="Path%202.svg">
<div class="modernForm">
    <div class="imageSection">
        <div class="image">
            <img src="form.png">
        </div>
    </div>
    <div class="contactForm">
        <h1>Employees Management</h1>
        <form method="post">
            <div class="input-wrapper">
                <label class="label" for="name">Name</label>
                <input class="input" type="text" id="name" name="name" value="<?php echo $employee->form_name ?>">
            </div>
            <div class="input-wrapper">
                <label class="label" for="phone">Phone</label>
                <input class="input" type="number" id="phone" name="phone" value="<?php echo $employee->form_phone ?>">
            </div>
            <div class="input-wrapper address">
                <table>
                    <tr>
                        <td>
                            <label for="street">street</label></td><td>
                            <input class="input" type="number" id="street" name="street" value="<?php echo $employee->form_street ?>">
                        </td>
                        <td>
                            <label for="building">building</label></td><td>
                            <input class="input" type="number" id="building" name="building" value="<?php echo $employee->form_building ?>">
                        </td>
                        <td>
                            <label for="region">region</label></td><td>
                            <input class="input" type="text" id="region" name="region" value="<?php echo $employee->form_region ?>">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <label for="city">city</label></td><td>
                            <input class="input" type="text" id="city" name="city" value="<?php echo $employee->form_city ?>">
                        </td>
                        <td>
                            <label for="country">country</label></td><td>
                            <input class="input" type="text" id="country" name="country" value="<?php echo $employee->form_country ?>">
                        </td>
                    </tr>

                </table>
            </div>
            <div class="input-wrapper">
                <label for="email">E-mail</label>
                <input class="input" type="email" id="email" name="email" value="<?php echo $employee->form_email ?>">
            </div>
            <div class="actions">
                <button class="action" type="submit" name="Insert">insert</button>
                <button class="action" type="submit" name="Update">update</button>
                <button class="action" type="submit" name="Delete">delete</button>
                <button class="action" type="submit" name="Search">Search</button>
                <button class="action" type="submit" name="Previous">Previous</button>
                <button class="action" type="submit" name="Next">Next</button>
            </div>
        </form>
    </div>
</div>
</body>
</html>