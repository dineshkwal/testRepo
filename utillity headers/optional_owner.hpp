#include <cassert>
#include <memory>

namespace utility
{
	template<typename T>
	class optional_owner
	{
	public:
		constexpr optional_owner() noexcept = default;

		constexpr optional_owner(T* nonOwningT) noexcept
			: mPointer(nonOwningT)
			, mOwner(false)
		{
		}

		constexpr optional_owner(T& nonOwningT) noexcept
			: mPointer(&nonOwningT)
			, mOwner(false)
		{
		}

		optional_owner(std::unique_ptr<T> owningT) noexcept
			: mPointer(owningT.release())
			, mOwner(true)
		{
		}

		~optional_owner()
		{
			reset();
		}

		constexpr optional_owner(optional_owner&& other) noexcept
			: mPointer(other.mPointer)
			, mOwner(other.mOwner)
		{
			other.mPointer = nullptr;
			other.mOwner = false;
		}

		optional_owner& operator=(optional_owner&& other) noexcept
		{
			reset();

			mPointer = other.mPointer;
			mOwner = other.mOwner;

			other.mPointer = nullptr;
			other.mOwner = false;

			return *this;
		}
        
		optional_owner(const optional_owner&) = delete;

		optional_owner& operator=(const optional_owner&) = delete;

		void reset() noexcept
		{
			if (mOwner && mPointer)
			{
				delete mPointer;
			}
			mPointer = nullptr;
			mOwner = false;
		}

		constexpr explicit operator bool() const noexcept
		{
			return mPointer != nullptr;
		}

		constexpr bool operator!() const noexcept
		{
			return mPointer == nullptr;
		}

		T* operator->() const
		{
			assert(mPointer != nullptr);

			return mPointer;
		}

		T& operator*() const
		{
			assert(mPointer != nullptr);

			return *mPointer;
		}

		constexpr T* get() const noexcept
		{
			return mPointer;
		}

		constexpr bool owner() const noexcept
		{
			return mOwner;
		}

	private:
		T* mPointer = nullptr;
		bool mOwner = false;
	};

} // namespace utility
