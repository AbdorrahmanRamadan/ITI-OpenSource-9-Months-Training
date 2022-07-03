class ProductsController < ApplicationController
  before_action :authenticate_user! , only: [:new,:edit,:destroy]

  def index
    @products = Product.all
  end

  def show
    @product = Product.find(params[:id])
  end


  def new
    @product = Product.new
  end

  def create
    @product = Product.new(product_params)
    @product.user_id = current_user.id
    if @product.save
      UserMailer..with(id:current_user.id).post_created.de
      redirect_to @product , notice: "product added"
    else
      render :new, status: :unprocessable_entity
    end
  end

  def edit
      @product = Product.find(params[:id])
  end

  def update
    @product = Product.find(params[:id])

    if @product.update(product_params)
      redirect_to @product, notice: "product updated"
    else
      render :edit, status: :unprocessable_entity
    end
  end

  def destroy
    @product = Product.find(params[:id])
    @product.destroy

    redirect_to root_path, status: :see_other
  end

  # protected
  # def authenticate_user!
  #   unless Current.user
  #     redirect_to sign_in_path, :notice => 'pls log in first'
  #
  #   end
  # end


  private
  def product_params
    params.require(:product).permit(:name, :description,:price,:image)
  end
end
