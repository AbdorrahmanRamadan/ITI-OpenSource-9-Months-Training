
require 'faker'
Role.destroy_all
Role.create(name:'super admin',description:'super admin on all operations')
Role.create(name:'admin',description:'admin edits his own infos')

User.destroy_all

User.create(name: 'AbdorrahmanRamadan', email:'AbdorrahmanRamadan@gmail.com',password:'123ewqasd',password_confirmation:'123ewqasd',role_id:1)

5.times do |i|
  f_name = Faker::Name.first_name
  User.create(
    name: f_name,
    email: Faker::Internet.email(name: f_name),
    password:"123ewqasd",
    password_confirmation:"123ewqasd",
    role_id:2
  )
end
Product.destroy_all
20.times do |i|
  Product.create(
    name: Faker::Food.dish,
    description: Faker::Lorem.sentence(word_count: 10, supplemental: false, random_words_to_add: 0).chop,
    price: 60.03,
    user_id:1
  )
end



