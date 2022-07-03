Rails.application.routes.draw do
  mount RailsAdmin::Engine => '/admin', as: 'rails_admin'
  get 'users/new'
  get 'users/create'

  devise_for :users
  scope '/admin' do
    resources :users
  end
  resources :roles

  resources :products
  root to: "products#index"
  # get "sign-up" , to: "registrations#new"
  # post "sign-up",to: "registrations#create"
  #
  # get "sign-in" , to: "sessions#new"
  # post "sign-in",to: "sessions#create"
  #
  #
  # delete "logout",to: "sessions#destroy"

end
